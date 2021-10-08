#!bin/bash

cp /tmp/phpmyadmin/config.inc.php /var/www/localhost/phpmyadmin
service php7.3-fpm start
