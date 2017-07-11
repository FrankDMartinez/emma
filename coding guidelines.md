The following are the coding guidelines this project is
currently attempting to use. In no particular order:

#Never ...
* ... break the build.
* ... throw exceptions.
* ... use `goto`.
* ... call `gets()`.
* ... prematurely optimize.
* ... cast away `const` except to call a `const`-incorrect function.
* ... `#define` anything except for `#include` guards, conditional compilation, and implementing `assert`.

#Classes
* Classes should have a single purpose.
* Data members should be `private`.

#Functions
* Function definitions never appear in headers unless they are function template definitions; elsewise, unnecessary compilation may result.
* No more than three levels of indentation in a function.
* "Functions should be short and sweet, and do just one thing. They should fit on one or two screenfuls of text (the ISO/ANSI screen size is 80x24, as we all know), and do one thing and do that well."
* No more than one statement per line.
* Parameters shall be references unless they are of a basic standard data type or a smart pointer.
* No function declarations with elipses.

#Declarations
* Pointers vs. references: use pointers if you want to do pointer arithmetic with them (e.g. incrementing the pointer address to step through an array) or if you ever have to pass a NULL-pointer; elsewise, use references.
* Declare no more than one variable per declaration.
* No more than one declaration per line.
* No global variables.
* If a variable can be declared `const`, do so.
* Non-parameter variables shall be initialized upon declaration, except for input buffers and those declared `volatile`.

#Other Visual Presentation
* Column limit: Write your code to fit within 80 columns of text, preferably 64. Doing so helps improve readability of printed out code and of code in an terminal window without resizing it.
* Don’t indent namespaces: In general, we strive to reduce indentation wherever possible. This is useful because we want code to fit into 80 (64) columns without wrapping horribly, but also because it makes it easier to understand the code. To facilitate this and avoid some insanely deep nesting on occasion, don’t indent namespaces. If it helps readability, feel free to add a comment indicating what namespace is being closed by a `}`.
* Commas should be followed by a space; not preceded by one.
* Affix asterisks and ampersands to types instead of names or floating them in between.
* No spaces immediately inside of parenthesis.
* Bracing: use the "one true brace" style unless specifically stated elsewise.

#Headers
* `#include` as little as possible; don't include a header containing a class definition when a forward declaration suffices.
* Every header shall `#include` every other header (and only every header) required to compile the contents of that file.
* Always write internal `#include` guards and never external ones.

#Miscellaneous
* Use the uniform initialization syntax whenever possible.
* "Correct is better than fast. Simple is better than complex. Clear is better than cute. Safe is better than insecure."
* Use named variables, not temporaries, as constructor/function arguments.
* Use prefix increment/decrement operators; not the postfix versions.

No, the irony of the long lines in this file is not lost on the Author.
