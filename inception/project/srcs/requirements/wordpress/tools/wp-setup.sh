#!/bin/bash
while ! mariadb -h$DB_HOST -u$DB_ADMIN -p$DB_ADMIN_PASSWORD; do
	echo " ➜ Waiting to connect to MariaDB"
	sleep 2
done

if [ -f wp-config.php ]; then
	echo " ➜ Wordpress is ready. "
else
	wp core download --allow-root
	
	wp config create \
		--dbname="$DB_NAME" \
		--dbuser="$DB_ADMIN" \
		--dbpass="$DB_ADMIN_PASSWORD" \
		--dbhost="$DB_HOST" --allow-root \
		
	wp core install \
		--url="$DOMAIN_NAME" \
		--title="inception" \
		--admin_user="$WP_ADMIN" \
		--admin_password="$WP_ADMIN_PASSWORD" \
		--admin_email="$WP_ADMIN_MAIL" \
		--skip-email --allow-root

	wp user create $WP_USER $WP_MAIL \
		--user_pass=$WP_USER_PASSWORD \
		--role=author --allow-root

	# wp theme install twentysixteen \
	wp theme install oceanwp \
		--activate
	
fi

echo "\n ➜ Visit https://nuxu.42.fr"

php-fpm8.0 -F

