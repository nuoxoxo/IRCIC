/*
import * as fs from "fs";

fs.readFile("filename.txt", "utf8", (err: Error, data: string) => {
  if (err) {
    console.error(err);
    return;
  }

  console.log(data);
});
*/

/*
import fs from 'node:fs'
fs.readFile('subject.in', 'utf8', (err: Error, data: string) => {
    if (err) {
        console.log(err)
        return
    }
    console.log(data)
})
*/

import * as fs from 'fs';

const lines = fs.readFileSync('subject.in', 'utf-8')
console.log(lines)
