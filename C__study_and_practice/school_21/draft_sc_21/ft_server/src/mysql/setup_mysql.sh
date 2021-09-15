#!bin/bash

echo ""
echo "_______________mySQL__________________-"

service mysql start

echo "CREATE DATABASE wordpress;" | mysql -u root
#creating a local user [admin]  with a password
echo "CREATE USER 'admin'@'localhost' IDENTIFIED BY 'school21';" | mysql -u root
#Next, we will give the same user all rights over this database:
echo "GRANT ALL ON wordpress.* TO 'admin'@'localhost';" | mysql -u root
#update the MySQL user rights table in memory
echo "FLUSH PRIVILEGES;" | mysql -u root
