# Custom Character String Generator
Transcribe strings with custom defined character sets.

### Character Definition
Custom character sets are defined in comma separated values files (.csv).
Character sets *must* define ASCII space ( , decimal 32) through backtick (\`, decimal 96).
Note that this excludes lower case letters a-z, |, {, }, and ~.

The first line defines character width (in characters), character height (in characters), foreground character, and background character.

The remaining lines define each representation for each required ASCII value (0-9, A-Z, etc.). An `f` is forground, and a `b` is background.

#### Example
This will define 5x5 characters: ' ' (space), '0', and '1'

    5,5,@, 
     ,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b
    0,b,f,f,f,b,f,b,b,b,f,f,b,b,b,f,f,b,b,b,f,b,f,f,f,b
    1,b,b,f,b,b,b,f,f,b,b,b,b,f,b,b,b,b,f,b,b,f,f,f,f,f

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

### Building
This project uses SCons build system. Run `scons` from the directory to build and `scons -c` to clean.


### ToDo
[ ] output to file
