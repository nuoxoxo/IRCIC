#!/bin/bash

if [ ! -f "/var/www/html/wordpress/wp-config.php" ]; then
    wp core download --allow-root
    wp core config --dbname=$WP_DATABASE_NAME --dbuser=$WP_DATABASE_USR --dbpass=$WP_DATABASE_PWD --dbhost=$MYSQL_HOST --allow-root
    wp core install --url=$DOMAIN_NAME --title=$WP_TITLE --admin_user=$WP_ADMIN_USR --admin_password=$WP_ADMIN_PWD --admin_email=$WP_ADMIN_EMAIL --skip-email --allow-root
    wp user create $WP_USR $WP_EMAIL --role=editor --user_pass=$WP_PWD --allow-root
fi

/usr/sbin/php-fpm8 -F -R