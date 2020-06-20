# Progalap-Sakk

## Fordítás és futtatás:

Debug módban (nincs system("clear"), integritás tesztekhez)
```sh
cmake -H. -Bbuild -DCMAKE_BUILD_TYPE=Debug
cmake --build build/ --target all -- j 2
./build/program/sakk-exe
```
Terminálban való próbálgatáshoz érdemes Release üzemmódban buildelni.

## Integritás tesztek elkészítése és futtatása, build-en belül:
```sh
make integrity-test-...
```
Ahol a "..." helyére Fischer, castle, promotion kerülhet.
Az output txt fájlokban van elmentve a message által megjelölt helyen.
(Itt a tesztekhez nem készült automatikus kiértékelés, kézzel kell megnyitni a fileokat, vagy
 terminálra kiíratni, és megnézni, hogy az inputra megfelelő output jött-e létre.)


## Egység tesztek futtatása (build-en belül)

```sh
./testing/unit/test_sakk
```