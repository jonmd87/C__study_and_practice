#!bin/bash

echo "~~~~~~~~~~~~~~~~~~~ START SETUP APPLICATION ~~~~~~~~~~~~~~~~~~~"

/tmp/ssl/setup_ssl.sh
/tmp/nginx/setup_nginx.sh
/tmp/mysql/setup_mysql.sh
/tmp/phpmyadmin/setup_phpmyadmin.sh
/tmp/wordpress/setup_wordpress.sh

bash
