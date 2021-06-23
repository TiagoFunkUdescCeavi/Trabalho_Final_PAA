#!/bin/bash

CSV_FILE=./assets/data_size_2.csv
BINARY=TRABALHO_FINAL_PAA
EXECUTIONS=30

generate_csv() {

  # numbers=(10000000 100000000 200000000 300000000 400000000 500000000 600000000)
  numbers=(270000 810000 2430000 7290000 21870000 65610000)

  echo "EXECUTION;SIZE;TIME" >> $CSV_FILE
  for number in "${numbers[@]}"
  do
    for exec in `seq $EXECUTIONS`
    do
      echo "Excution ${exec} for number ${number}"
      echo -n "${exec};" >> $CSV_FILE
      ./$BINARY $number >> $CSV_FILE
      echo >> $CSV_FILE # /n
    done
  done

}

rm $CSV_FILE
make clean
make
generate_csv
