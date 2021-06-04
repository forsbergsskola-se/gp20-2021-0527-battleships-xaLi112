## 1. FILE I/O with libC

#### **Functions**
- `fopen`	– open a file
- `fclose` – close a file
- `fseek` – go to a specific position inside the file
- `ftell` – find out where you are inside the file
- `fprintf` – print text into a file
- `fgetc` – read a single character from the file

---

## 2. Opening, Closing
````c++
FILE* fp = fopen("faust.txt", "rb");
if(fp)
{
	// do something useful here

	fclose(fp);
}
````
#### **`fopen`**
- Returns `FILE*`, equals 0 if file could not be opened
- Open mode as a `string`
  <br></br>
  - `r` = read (file must exist)
  - `w` = write
  - `a` = append
  - `r+` = read and write (file must exist)
  - `w+` = read and write (file is always overwritten)
  - `b` = binary

---
## 3. Getting File Size
````mermaid
FILE* fp = fopen("faust.txt", "rb");
if(fp)
{
	fseek(fp, 0, SEEK_END);
	long iFileSize = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	fclose(fp);
}
````
- No `C` function to get file size
- Windows has such a function, of course

#### **Trick:**
- Use `fseek` to go to end of file
- Use `ftell` to find out where you are
- Use `feek` to go back to the beginning of the file

---

## 4. Exercise

#### **Count the words in Goethe’s Faust!**
- How many words?
- How many different words?
- How many times does each word appear?

#### **Hints:**
- Read the file character by character using getc
- Words stop at spaces, line breaks, points, commas, semicolons etc.
- Filter out punctuation marks
- Create a list of strings for the words you already know
- If a word appears for the second time, increment a counter for that word!

---
