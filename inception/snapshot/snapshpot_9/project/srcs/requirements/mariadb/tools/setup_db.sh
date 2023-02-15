#!/bin/bash

if [ -d "/var/lib/mysql/$DB_NAME" ]; then
	echo "DB exists"
else
	echo "Setting up DB"
	touch file
	chmod 755 file
	mysql_install_db 2> /dev/null

	cat << EOF > file
CREATE DATABASE $DB_NAME;
FLUSH PRIVILEGES;
GRANT ALL PRIVILEGES ON *.* TO 'root'@'localhost' IDENTIFIED BY '$DB_ROOT_PASSWORD' WITH GRANT OPTION;
FLUSH PRIVILEGES;
CREATE USER '$DB_ADMIN'@'%' IDENTIFIED BY '$DB_ADMIN_PASSWORD';
GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$DB_ADMIN'@'%';
DROP DATABASE IF EXISTS test;
FLUSH PRIVILEGES;
EOF

# --bootstrap to execute sql script before any privileges exits
	mysqld --bootstrap < file 2> /dev/null
	rm file

fi

mysqld 2> /dev/null

