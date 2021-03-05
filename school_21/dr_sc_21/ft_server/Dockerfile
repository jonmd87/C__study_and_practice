FROM debian:buster
LABEL maintainer="Lakenya Bradly <lbradly@student.21-school.ru>"

#instalation
RUN apt-get -y update && apt-get -y upgrade
RUN apt-get -y install nginx
RUN apt-get -y install vim 
RUN apt-get -y install unzip
RUN apt-get -y install mariadb-server
RUN apt-get -y install wget
RUN apt-get -y install php php-mysql php-cli php-fpm php-mbstring php-zip php-gd

#make sub_dir
RUN mkdir /var/www/localhost
RUN mkdir /var/www/localhost/nginx
RUN mkdir /var/www/localhost/phpmyadmin

#install phpMyAdmin
RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.zip
RUN unzip phpMyAdmin-4.9.0.1-all-languages.zip
RUN mv phpMyAdmin-4.9.0.1-all-languages /var/www/localhost/phpmyadmin
RUN rm phpMyAdmin-4.9.0.1-all-languages.zip 

#install WordPress
RUN wget http://wordpress.org/latest.tar.gz
RUN tar -xzvf latest.tar.gz
RUN mv ./wordpress /var/www/localhost
RUN rm latest.tar.gz

#copy config_files
COPY src /tmp/

EXPOSE 80
EXPOSE 433

CMD bash /tmp/run.sh
