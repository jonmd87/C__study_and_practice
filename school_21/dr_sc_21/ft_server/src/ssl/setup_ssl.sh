#!bin/bash

echo ""
echo "CREATE SSL"
SSL_PATH=/etc/nginx/ssl

mkdir $SSL_PATH
chmod -R 600 $SSL_PATH

openssl req -newkey rsa:4096 \
            -x509 \
            -sha256 \
            -days 3650 \
            -nodes \
            -out $SSL_PATH/localhost.crt \
            -keyout $SSL_PATH/localhost.key \
			-subj "/C=RU/ST=Moscow/L=Vyatskaya/O=School21/CN=lbradly"
echo "SSL DONE"
