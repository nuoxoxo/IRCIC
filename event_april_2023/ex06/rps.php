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

	# if ( ($pc != 0 && $me > $pc) || ($pc == 0 && $me == 2) ) {
	if ( ($pc != 0 && $me > $pc) ) {
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
