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
	# my @all = split('', $s); # same op

	my $half = $#all / 2;

	# print "$half - $#all - $s \n";
	# foreach (@all) { print "$_\n"; }

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

