FROM    alpine:3.16

ARG     VER=8 \
        DB_NAME \
        DB_USER \
        DB_PASS

RUN     apk update && apk upgrade && \
        apk add --no-cache wget unzip \
        php${VER} \
        php${VER}-fpm \
        php${VER}-redis \
        php${VER}-json \
        php${VER}-mysqli \
        php${VER}-curl \
        php${VER}-dom \
        php${VER}-exif \
        php${VER}-fileinfo \
        php${VER}-hash \
        php${VER}-imagick \
        php${VER}-mbstring \
        php${VER}-openssl \
        php${VER}-pcre \
        php${VER}-xml \
        php${VER}-zip \
        sed -i "s|listen = 127.0.0.1:9000|listen = 9000|g" \
            /etc/php8/php-fpm.d/www.conf && \
        sed -i "s|;listen.owner = nobody|listen.owner = nobody|g" \
            /etc/php8/php-fpm.d/www.conf && \
        sed -i "s|;listen.group = nobody|listen.group = nobody|g" \
            /etc/php8/php-fpm.d/www.conf && \
        && rm -f /var/cache/apk/*