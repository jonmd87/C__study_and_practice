#!bin/bash

echo ""
echo "--------------SETUP NGINX--------------"

service nginx start
cp /tmp/nginx/nginx.conf /etc/nginx/sites-available/nginx.conf
ln -s /etc/nginx/sites-available/nginx.conf /etc/nginx/sites-enabled
rm -rf /etc/nginx/sites-enabled/default

#checking work nginx
nginx -t

service nginx restart
