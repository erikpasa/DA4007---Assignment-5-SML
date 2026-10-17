# DA4007---Assignment-5-SML

## Introduction
Assignment 5 in the course Programming techniques II DA4007 at Stockholm University, during my master's in Computational Physics. We are asked to create a small language model (SML), according to certain specifications.

## Description
The SML reads a txt file, a training text, where it treats the text as bytes, and counts k-grams. A k-gram is a substring of a certain length of the txt file, so when it counts them it checks how many times they occur. For each k-gram the SML also counts how many times each character follows it. With these counts the SML can create weights to create new character outputs. To be able to also output characters which do not appear in the training text, the weights also introduce a pseudocount. The next character is sampled at random according to the weights, using a random engine that is seeded differently on every run, so the output is different each time. The SML writes output up to a certain length, but if the current output k-gram is not followed by any letter in the training text, and no pseudocount is used, the output stops.

## Build
To build the SML a Makefile is used, where C++17 is required. When in the right directory, the following command will compile the necessary code:

```
make
```

To clean, use:

```
make clean
```

This removes the executable `slm` and the generated object and dependency files.

## Usage
After compiling the program, run it with:

```
slm [-a pseudocount] k file length
```

The program is run from the project's top directory.

- The argument `[-a pseudocount]` is an optional argument. The pseudocount has to be a number bigger than or equal to 0. When this (`-a`) argument is not given, the pseudocount is 0. This means that the characters generated are only the ones included in the training text.
- The `k` argument is the length of the k-grams. It has to be an integer bigger than zero, and smaller than the number of characters in the training text.
- The `file` argument is the name of the training text file, e.g. `training_textfile.txt`. The file has to exist on the computer, and the path given has to be correct.
- The `length` argument is the wanted length for the output. It has to be an integer, and it has to be equal to or bigger than the `k` argument.

## Examples
A simple example run is:

```
input: ./slm 5 src/moby_dick.txt 100
output: ered and away from Garnery. For eight would be
requires of Louis the old man saying, Stubb—there 
```

An example of a run with pseudocount enabled:

```
input: ./slm -a 0.001 3 src/moby_dick.txt 100
output: e foress fight beging over, the
Therefusine,

AZORE SAILOR. (_Ther; ye,
sould Europened my man?
```

An example of a run with wrong arguments:

```
input: ./slm 2 no_such_file.txt 100
output: slm: cannot open file 'no_such_file.txt'
```

## Observations
We observe that for low k only certain small English words are produced, and for the most part it is gibberish. When increasing k the SML creates more understandable words, and its output almost reads like a passage from the training text.

With the pseudocount option enabled, new characters get introduced, such as `]`. With a relatively high pseudocount the SML can get stuck with these characters and create gibberish like: `?pW7Ahpcd?)?0?7?mVmPN]?My ?G2?!`. With a lower pseudocount, the sentences become more sensible again. We also observe that if we increase k, but not the pseudocount, the output becomes gibberish. Therefore, to output sensible words with a higher k, a lower pseudocount is required.

## Training Texts
The training texts used when making and testing were "Moby Dick" and "A Modest Proposal", from Project Gutenberg. These are not included in the repository.
