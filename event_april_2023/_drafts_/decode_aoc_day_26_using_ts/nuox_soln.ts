import * as fs from 'fs';

let file: string

// Switch infile

file = 'subject.in'
// file = 'test.in'


// Solver
const line = fs.readFileSync(file, 'utf-8')

// console.log('test : ' + line)
console.log('part 1: ' + p1(line))
console.log('part 2: ' + p2(line))


// Fn

function p2(s: string): string {
    let res = ''
    let i = 0
    let zero = '0'.charCodeAt(0)
    let nine = '9'.charCodeAt(0)
    for (let i = 0; i < s.length; i++) {
        let c = s[i]
        let code = c.charCodeAt(0)
        if (code <= nine && code >= zero && i < s.length - 1 && c == s[i + 1]) {
            res += c
            i++
        }
    }
    return res
}

// arrow fn cannot be hoisted ***
// const subject = (line: string): string => {

function p1(line: string): string {
    let res: string = ''
    let i: number = 0
    let A = 'A'.charCodeAt(0)
    let Z = 'Z'.charCodeAt(0)

    while (i < line.length) {
        let c = line[i]
        let code = c.charCodeAt(0)
        if (((code <= Z && code >= A) || c == '-') &&
            i < line.length - 1 && c == line[i + 1]) {
            res += c
            i += 2
        } else {
            ++i
        }
    }
    return res
}


