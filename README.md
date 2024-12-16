# Hash Comparison: djb2 vs sdbm

This repository contains a comparison between the **djb2** and **sdbm** hash algorithms. It includes implementations of both algorithms in C and evaluates their performance in terms of speed and collision rates.

## Files

- **djb2.c**: Implementation of the **djb2** hash algorithm.
- **sdbm.c**: Implementation of the **sdbm** hash algorithm.
- **large.txt**: A dictionary used by both the algorithms for comparison.
- **result.txt**: File containing the comparison results between the two algorithms.

## Installation

To run any of these projects, you need to have a C compiler (like GCC) and basic knowledge of socket programming.

## Steps to run:

1. Clone the repository:
    ```bash
    git clone https://github.com/ddas09/hash.git
    cd hash
    ```

2. Compile both the files:
    ```bash
    gcc -o djb2 djb2.c
    gcc -o sdbm sdbm.c
    ```

3. Run both programs and compare the results:
    ```bash
    ./djb2 large.txt > result_djb2.txt
    ./sdbm large.txt > result_sdbm.txt
    ```
4. The comparison results will be stored in the file of your choice.

## Contributing

1. Fork the repository.

2. Create a new branch:
   ```bash
   git checkout -b feature/your-feature
   ```
3. Make your changes.
4. Commit your changes 
   ```bash
   git commit -a 'Add new feature'
   ```
5. Push to the branch 
   ```bash
   git push origin feature/your-feature
   ```
6. Create a new Pull Request.

## License
This project is open-source and licensed under the [MIT License](https://opensource.org/license/mit).