

function merge_sort(arr) {
	if (arr.length < 2)
		return

	// split
	let len = arr.length
	let mid = Math.floor(len / 2)
	let L = []
	let R = []
	for (let i = 0; i < mid; i++) {
		L.push(arr.pop())
	}
	for (let i = 0; i < mid; i++) {
		R.push(arr.pop())
	}

	// recurse
	merge_sort(L)
	merge_sort(L)

	// insert
	while (L.length != 0 && R.length != 0) {
		if (L[0] > R[0]) {
			arr.push(R.pop(0))
		} else {
			arr.push(L.pop(0))
		}
	}

	// the rest
	while (L.length != 0) {
		arr.push(L.pop(0))
	}
	while (R.length != 0) {
		arr.push(R.pop(0))
	}
}

function print_array(arr, msg='') {
	
}

function test(arr) {
	
}
