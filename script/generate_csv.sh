#!/bin/bash

CSV_FILE=./assets/data.csv
BINARY=TRABALHO_FINAL_PAA
EXECUTIONS=1000

generate_csv() {

  numbers=(10 100 1000 10000 100000 1000000 10000000)

  echo "EXECUTION;NUMBER;TIME" >> $CSV_FILE
  for number in "${numbers[@]}"
  do
    for exec in `seq $EXECUTIONS`
    do
      echo "Excution ${exec} for number ${number}"
      ./$BINARY $exec $number >> $CSV_FILE
      echo >> $CSV_FILE
    done
  done

}

rm $CSV_FILE
make clean
make
generate_csv