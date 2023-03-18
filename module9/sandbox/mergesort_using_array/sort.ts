const process = require('process')

if (process.argv.length == 2) {
	let arr = new Array()

	arr = [3, 5, 9, 7, 4]
	test(arr)
	arr = [2, 11, 1, 42, 21, 1000, 6, 3, -42]
	test(arr)
	arr = [2, 11, 1, 42, 21, 1000, 6, 3, -42, 21]
	test(arr)
}

function merge_sort(arr) {
	if (arr.length < 2)
		return

	// split
	let len = arr.length
	let mid = Math.floor(len / 2)
	let L = [] //= arr.slice(mid, len).reverse()
	let R = [] //arr.slice(0, mid).reverse()

	for (let i = 0; i < mid; i++) {
		R.push(arr.pop())
	}
	for (let i = 0; i < len - mid; i++) {
		L.push(arr.pop())
	}

	// console.log(L)
	// console.log(R)

	// recurse
	merge_sort(L)
	merge_sort(R)

	// insert
	while (L.length != 0 && R.length != 0) {

		if (L[0] < R[0]) {
			arr.push(L.shift())
		} else {
			arr.push(R.shift())
		}
	}

	// the rest
	while (L.length != 0) {
		arr.push(L.shift())
	}
	while (R.length != 0) {
		arr.push(R.shift())
	}
}

function print_array(arr) {
	process.stdout.write('[');
	for (let i = 0; i < arr.length; i++) {
		let n = arr[i]
		let len = arr.length
		let sep = i == len ? ' ' : ', '
		process.stdout.write(arr[i] + sep);
	}
	process.stdout.write('] ');
}

function print_result(arr, end='') {
	let len = arr.length
	if (len > 12) {
		print_array(arr.slice(0, 6))
		console.log('[...]', len, end)
	} else {
		print_array(arr)
		console.log(len, end)
	}
}

function test(arr) {
	print_result(arr)
	merge_sort(arr)
	print_result(arr, '(sorted) \n')
}
