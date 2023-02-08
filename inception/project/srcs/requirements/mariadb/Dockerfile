FROM		alpine:3.16

RUN		apk update && apk add --no-cache  mariadb  mariadb-client
# no caching
# each RUN directive creates a `layer` in docker image
	# -> so, don't do unnecessary RUNs


# First layer - normalize the config
RUN		mkdir /var/run/mysqld; \
		chmod 777 /var/run/mysqld; \
		{ \
			echo '[mysqld]'; \
			echo 'skip-host-cache'; \
			echo 'skip-name-resolve'; \
			echo 'bind-address=0.0.0.0'; \
		} \
		| tee /etc/my.cnf.d/docker.cnf; \
		sed -i	"s|skip-networking|skip-networking=0|g" \
			/etc/my.cnf.d/mariadb-server.cnf

# tee : send output of echo to a file
# why use `skip-networking=0` ??


# Second layer : create DB and set its path based on Layer 1
RUN		mysql_install_db	\
		--user=mysql		\
		--datadir=/var/lib/mysql

# open mariaDB working port
EXPOSE		3306
USER		mysql


# under previously created `mysql` we start up the DB

COPY		requirements/mariadb/conf/generate_db.sh . 
		# ⤷ changed

RUN		sh generate_db.sh && rm generate_db.sh
		# ⤷ added

CMD		["/usr/bin/mysqld", "--skip-log-error"]
