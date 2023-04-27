# Event April 2O23

final edit: by @qxqxia

![](https://i.imgur.com/O5IybGa.jpg)

- [ ] ex17 : blue part is `This is a hidden message (can you find it?)`
- [x] ex16
- [x] ex15 : stegno
- [x] ex14 : sast
- [ ] ex13 : jungle text game
- [ ] ex12 : smtp
- [ ] ex11 : api
- [x] ex10 : cipher
- [x] ex09
- [x] ex08 : blackjack
- [x] ex07
  - best: `main(c,v,e)char**e;{((void(*)())e+1)(v);}`
  - axel: `main(a,b)char**b;{if(a==3)return*--b[2]=32,puts(b[1]),2;}`
  - mine: `main(c,v)char**v;{return c^3?0:(printf("%s %s\n",v[1],v[2]),2);}`
- [x] ex06
- [x] ex05
- [x] ex04, ex03
- [x] ex02
- [x] ex01


# ex15 : stegno on a png
```
head 42.png
file 42.png
strings 42.png
exiftool 42.png
xxd 42.png
binwalk 42.png
```


# ex10 : symbolum

subject
```
Veh jxyi unuhsysu oek mybb xqlu je mhyju jxu fqiimeht yd q iocrebkc.jnj vybu.

:: Rot [A-Z]+16 ::
For this exercice you will have to write the password in a symbolum.txt file.
```

k
```
Q29uZ3JhdHVsYXRpb25zIG9uIGRlY29kaW5nIHRoaXMgbGluZSwgdGhlIGZpcnN
0IGxldHRlciBpczogaw==

:: base64 ::
echo "Q29uZ3JhdHVsYXRpb25zIG9uIGRlY29kaW5nIHRoaXMgbGluZSwgdGhlIGZpcnN
0IGxldHRlciBpczogaw==" | base64 --decode
Congratulations on decoding this line, the first letter is: k 
```

h
```
Xlmtizgfozgrlmh lm wvxlwrmt gsrh ormv, gsv gsriw ovggvi rh: s

:: atbash ::
Congratulations on decoding this line, the third letter is: h
```

2
```
67 79 78 71 82 65 84 85 76 65 84 73 79 78 83 79 78 68 69 67 79 68 73 78 71 84 72
73 83 76 73 78 69 84 72 69 78 69 88 84 67 72 65 82 65 67 84 69 82 73 83 50

:: ascii ::
CONGRATULATIONSONDECODINGTHISLINETHENEXTCHARACTERIS2
```

J
```
Charlie Oscar November Golf Romeo Alpha Tango Uniform Lima Alpha Tango
India Oscar November Sierra ... Oscar November ... Delta Echo Charlie Oscar
Delta India November Golf ... Tango Hotel India Sierra ... Lima India November
Echo ... Tango Hotel Echo ... November Echo X-Ray Tango ... Lima Echo Tango
Tango Echo Romeo ... India Sierra ... Juliett

:: nato phonetic alpha ::
C O N G R A T U L A T I O N S O N D E C O D I N G T H I S L I N E T H E N E X T L E T T E R I S J
```

F
```
C0N6r47U14710N5 0N D3C0D1N6 7H15 11N3 7H3 N3X7 13773r 15 F

:: Leet Speak 1337 ::
CONGrATUIATIONS ON DECODING THIS IINE THE NEXT IETTEr IS F

```

S
```
Congratulations on decoding this line, the next letter is: _
RSOEBLNZAYNDQOT QT IKITREUM OEBO YEUM, NKG AYTN PGSZNMB RT: K

:: chatGPT::
R -> C
S -> o
O -> n
E -> g
B -> r
L -> a
N -> t
Z -> u
A -> l
Y -> d
D -> i
Q -> c
T -> o
I -> g
K -> s
U -> e
M -> x

Applying this mapping to the rest of the message, "NKG AYTN PGSZNMB RT: K", we get:

"AND WELL DONE FINALLY IT TRANSLATES TO: S"

Therefore, the decoded message is "Congratulations on decoding this line, and well done. Finally, it translates to: S".
```

# ex09 : frame
```c
int	main(int c, char **v)
{
	size_t		len, max = 0;
	size_t		trail;
	char		**G;
	int	i;

	if (c ^ 2)
		return 0;

	char	*s = v[1];

	G = ft_split(s, ' ');

	i = -1;
	while (G[++i])
	{
		len = strlen(G[i]);
		max = len > max ? len : max;
		// printf("%zu\n", len);
	}

	max += 5;

	char	shangxia[max];

	i = -1;
	while (++i < (int) max) shangxia[i] = (i ^ max - 1) ? '*' : '\0';

	printf("%s\n", shangxia);
	i = -1;
	while (G[++i])
	{
		printf("* %s", G[i]);
		trail = max - strlen(G[i]) - 4;
		while (--trail > 0)	printf(" ");
		printf(" *\n");
	}
	printf("%s\n", shangxia);
}
```

# ex07 : C golf

# ex06 : PHP Rock paper scissors
```php
<?php

$pool = array(
	"paper",
	"scissors",
	"rock"
);

$input = (string) readline("Choose rock, paper, or scissors: ");
$my_choice = strtolower($input);

if ( in_array($my_choice, $pool, true) ) {

	$pc_choice = $pool[array_rand($pool, 1)];

	$me = array_search($my_choice, $pool);
	$pc = array_search($pc_choice, $pool);

#	echo "$my_choice, $me, $pc_choice, $pc \n";

	if ( ($pc != 0 && $me > $pc) || ($pc == 0 && $me == 2) ) {
		echo "Congratulations! You won! The computer chose $pc_choice.";
	} else if ($pc == $me) {
		echo "Tie!";
	} else {
		echo "Sorry, you lost. The computer chose $pc_choice.";
	}

} else {
	
	echo "'$my_choice' is not a valid choice. \n";
}

?>
```

# ex05 : Perl palin
```pl
use strict;
use warnings;

print "Enter a string: ";
my $s = <STDIN>;
chomp $s; # chomp the trailing nl

if ($s eq "")  {

	print "The string is a palindrome!\n";

} else {

	my $is_palin = 1;
	my @all = split //, $s;
	my $half = $#all / 2;

	# print "$half $#all $s"

	foreach my $i ( 0 .. $half ) {
	    my $count = 0;
	    if ( $all[$i] ne $all[ -( $i + 1 ) ] ) {
		$is_palin = 0;
		last;
	    }
	}

	if ($is_palin) {
	    print "The string is a palindrome!\n";
	} else {
	    print "The string is not a palindrome.\n";
	}
}
```

# ex03 : joke / ex04 : lyrics

# ex02 : touch me
```sh
echo 42 > _\\\\\!\\\@\#\$\%\\\^\\\&\\\*\\\(\\\)_\.\.\.\.\.\.txt
```

# ex01
```sh
#!/bin/bash

# L=$(basename "${BASH_SOURCE}"):0:3
# R=${L%\.*}

# L=$(ls)
# R=${L%\.*}

while :
do
	ls | sed "s/\.sh//g"
done
```



