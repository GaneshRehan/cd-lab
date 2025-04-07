#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to check if a line contains a single-line comment
int is_single_line_comment(const char *line) {
    // Look for "//" in the line
    const char *comment_start = strstr(line, "//");
    return (comment_start != NULL);
}

// Function to check if a line contains the start of a multi-line comment
int is_multi_line_comment_start(const char *line) {
    // Look for "/*" in the line
    const char *comment_start = strstr(line, "/*");
    return (comment_start != NULL);
}

// Function to check if a line contains the end of a multi-line comment
int is_multi_line_comment_end(const char *line) {
    // Look for "*/" in the line
    const char *comment_end = strstr(line, "*/");
    return (comment_end != NULL);
}

// Function to extract comments from a file
void extract_comments(const char *input_file, const char *output_file) {
    FILE *input_fp = fopen(input_file, "r");
    FILE *output_fp = fopen(output_file, "w");

    if (input_fp == NULL || output_fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int inside_multi_line_comment = 0; // Flag to track multi-line comments

    while (fgets(line, MAX_LINE_LENGTH, input_fp) != NULL) {
        // Remove trailing newline character
        line[strcspn(line, "\n")] = '\0';

        if (inside_multi_line_comment) {
            // Write the line if inside a multi-line comment
            fprintf(output_fp, "%s\n", line);

            // Check if the multi-line comment ends in this line
            if (is_multi_line_comment_end(line)) {
                inside_multi_line_comment = 0;
            }
        } else {
            // Check for single-line comments
            if (is_single_line_comment(line)) {
                fprintf(output_fp, "%s\n", line);
            }

            // Check for the start of a multi-line comment
            if (is_multi_line_comment_start(line)) {
                fprintf(output_fp, "%s\n", line);
                inside_multi_line_comment = 1;

                // Check if the multi-line comment ends in the same line
                if (is_multi_line_comment_end(line)) {
                    inside_multi_line_comment = 0;
                }
            }
        }
    }

    fclose(input_fp);
    fclose(output_fp);
}

int main() {
    const char *input_file = "exp3.c";
    const char *output_file = "comments.txt";

    // Extract comments and write to output file
    extract_comments(input_file, output_file);

    printf("Comments have been extracted and written to %s\n", output_file);

    return 0;
}