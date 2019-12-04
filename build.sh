#!/usr/bin/env sh

OUTPUT_NAME=rpg

build_assets () {
  echo "Building assets."
  assets2banks ./assets --compile

  mv bank*.h bank*.rel out/
}

if [ "$1" = "clean" ]; then
  echo "Cleaning build artifacts."
  rm out/*

  exit 0
fi

if [ "$1" = "assets" ]; then
  build_assets
  exit 0
fi

build_assets || exit 1

echo "Compiling sources..."
SOURCES=$(ls src/*.c)
for src in $SOURCES; do
  echo "  - $src"
  OUT="out/$(basename $src | sed 's/.c$/.rel/')"
  sdcc -mz80 -c --std-sdcc99 $src -o $OUT || exit 1
done

BANKS=$(ls out/bank*.h | sed 's/out\/bank\([0-9]\+\).h/\1/')
BANKS_FLAGS=

for i in $BANKS; do
  BANKS_FLAGS="${BANKS_FLAGS} -Wl-b_BANK${i}=0x8000"
done

echo "Building $OUTPUT_NAME.ihx..."
sdcc -mz80 --no-std-crt0 --data-loc 0xC000 \
  -o out/$OUTPUT_NAME.ihx \
  $BANKS_FLAGS \
  crt0/crt0_sms.rel $(ls out/*.rel) lib/SMSlib.lib || exit 1

echo "Outputting out/$OUTPUT_NAME.sms"
ihx2sms out/$OUTPUT_NAME.ihx out/$OUTPUT_NAME.sms || exit 1
