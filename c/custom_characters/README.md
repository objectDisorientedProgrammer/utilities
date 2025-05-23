# Custom Character String Generator
Transcribe strings with custom defined character sets.

### Character Definition
Custom character sets are defined in comma separated values files (.csv).
**Character sets must define** ASCII ` ` (space; decimal value 32) through ``` ` ``` (backtick; decimal value 96).
Note that this excludes lower case letters a-z, |, {, }, and ~. You may define them optionally.

**!! Note !!** the comma character `,` is a special case and must be defined as `comma`.

The first line defines character width (in characters), character height (in characters), foreground character, and background character.

The remaining lines define each representation for each required ASCII value (0-9, A-Z, etc.). An `f` is forground, and a `b` is background.

#### Example
This example snippet defines four, 5x5 characters: ' ' (space), ',' (comma), '0', '1', and 'B' with foreground `@` and background ` `.

    5,5,@, 
     ,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b
    comma,b,b,b,b,b,b,b,b,b,b,b,b,f,b,b,b,b,f,b,b,b,f,b,b,b
    0,b,f,f,f,b,f,b,b,b,f,f,b,b,b,f,f,b,b,b,f,b,f,f,f,b
    1,b,b,f,b,b,b,f,f,b,b,b,b,f,b,b,b,b,f,b,b,f,f,f,f,f
    B,f,f,f,f,b,f,b,b,b,f,f,f,f,f,b,f,b,b,b,f,f,f,f,f,b

See `encoding_example.csv` for more details.

### Running
`./transcribe encoding.csv text to be generated`

#### Example
Running `./transcribe encoding_example.csv hello 2025` will output:

    @   @ @@@@@ @     @     @@@@@      @@@   @@@   @@@  @@@@@
    @   @ @     @     @     @   @     @   @ @   @ @   @ @    
    @@@@@ @@@   @     @     @   @        @  @   @    @  @@@@ 
    @   @ @     @     @     @   @       @   @   @   @       @
    @   @ @@@@@ @@@@@ @@@@@ @@@@@     @@@@@  @@@  @@@@@ @@@@ 

Note that the output may become garbled if the terminal window is too small for a given string.

### Building
This project uses SCons build system. Run `scons` from the directory to build and `scons -c` to clean.
