The following are the coding guidelines this project is
currently attempting to use. In no particular order:

* Column limit: Write your code to fit within 80 columns of text, preferably 64. Doing so helps improve readability of printed out code and of code in an terminal window without resizing it.
* Don’t indent namespaces: In general, we strive to reduce indentation wherever possible. This is useful because we want code to fit into 80 (64) columns without wrapping horribly, but also because it makes it easier to understand the code. To facilitate this and avoid some insanely deep nesting on occasion, don’t indent namespaces. If it helps readability, feel free to add a comment indicating what namespace is being closed by a `}`.
* Exceptions: Don’t.
* `goto`: Don’t.
* Function definitions never appear in headers unless they are function template definitions; elsewise, unnecessary compilation may result.
* Affix asterisks and ampersands to types instead of names or floating them in between.
* No spaces inside of parenthesis.
* Commas should be followed by a space; not preceded by one.
* #include as little as possible; don't include a header containing a class definition when a forward declaration suffices.
* Pointers vs. references: use pointers if you want to do pointer arithmetic with them (e.g. incrementing the pointer address to step through an array) or if you ever have to pass a NULL-pointer; elsewise, use references.
* Use the uniform initialization syntax whenever possible.

No, the irony of the long lines in this file is not lost on the
Author.
