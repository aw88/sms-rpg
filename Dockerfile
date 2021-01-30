FROM debian:stable AS builder

# Install deps
RUN apt update && apt install -y \
  wget \
  bzip2 \
  git \
  gcc \
  && rm -rf /var/lib/apt/lists/*

# Pull SDCC snapshot and extract
RUN wget https://alexw-static.s3-eu-west-1.amazonaws.com/sdcc-snapshot-amd64-unknown-linux2.5-20210121-12016.tar.bz2 \
  && tar jxvf sdcc-snapshot-amd64-unknown-linux2.5-20210121-12016.tar.bz2 \
  && rm sdcc-snapshot-amd64-unknown-linux2.5-20210121-12016.tar.bz2

# Pull devkitSMS and extract
RUN git clone --depth=1 https://github.com/sverx/devkitSMS

RUN chmod +x /devkitSMS/assets2banks/src/assets2banks.py

# Build folder2c
WORKDIR /devkitSMS/folder2c/src/
RUN gcc folder2c.c -o folder2c

# Build ihx2sms
WORKDIR /devkitSMS/ihx2sms/src/
RUN gcc ihx2sms.c -o ihx2sms

# Build makesms
WORKDIR /devkitSMS/makesms/src/
RUN gcc makesms.c -o makesms

FROM debian:stable-slim

RUN apt update && apt install -y \
  dos2unix \
  python \
  && rm -rf /var/lib/apt/lists/*

COPY --from=builder /sdcc/ /
COPY --from=builder /devkitSMS/folder2c/src/folder2c /usr/local/bin/
COPY --from=builder /devkitSMS/assets2banks/src/assets2banks.py /usr/local/bin/assets2banks
COPY --from=builder /devkitSMS/ihx2sms/src/ihx2sms /usr/local/bin/
COPY --from=builder /devkitSMS/makesms/src/makesms /usr/local/bin/

# Symlink SDCC executable
RUN ln -s /sdcc/bin/sdcc /usr/local/bin/sdcc

WORKDIR /app
CMD ["bash", "-c", "dos2unix build.sh && sh build.sh"]
