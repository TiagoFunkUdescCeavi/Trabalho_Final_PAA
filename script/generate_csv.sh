#!/bin/bash

CSV_FILE=./assets/data_size_1.csv
BINARY=TRABALHO_FINAL_PAA
EXECUTIONS=30

generate_csv() {

  numbers=(10 100 1000 10000 100000 1000000 10000000 100000000)

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