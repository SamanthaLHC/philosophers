echo "ARG NUMBER PB:"
echo "\n"

./philo
./philo 1 2 3
./philo 1 2 3 4 5 6 7
echo "\n"

echo PASS A POSITIV NUMBER:
echo "\n"

./philo 11 -22 33 44 55
./philo 11 22 -33 44 55
./philo 11 22 33 -44 55
./philo 11 22 33 44 -55

echo "\n"

echo ONLY DIGITS REQUIRED
echo "\n"
./philo 1 -ab2 33 44 55
./philo 11 2-2 33 44 55
./philo 1a1 22 33 44 55
./philo a11 22 33 44 55
./philo 11a 22 33 44 55
./philo 11 22 a33 44 55
./philo 11 22 3a3 44 55
./philo 11 22 33a 44 55
./philo 11 +22 33 44 55
./philo _11 22 33 44 55
echo "\n"

echo "IF PHILO < 1 should return  err mess"
echo " \n"
./philo 0 1 2 3 4
./philo -11 22 33 44 55