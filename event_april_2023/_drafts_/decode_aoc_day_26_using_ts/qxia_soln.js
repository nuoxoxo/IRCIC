const fs = require('fs')
const test = fs.readFileSync('test.in', 'utf-8')
const subj = fs.readFileSync('subject.in', 'utf-8')

let regex_p1 = /([A-Z]|-)\1/g
let regex_p2 = /(\d)\1/g

const solve = (l, regex) => {
	let result = l.match(regex)
	// console.log(result)
	let s = ""
	for (let i = 0; i < result.length; i++)
		s += result[i][0]
	return s
}

console.log('test:')

console.log(solve(test, regex_p1))
console.log(solve(test, regex_p2), '\n')

console.log('subject:')
console.log(solve(subj, regex_p1))
console.log(solve(subj, regex_p2))




