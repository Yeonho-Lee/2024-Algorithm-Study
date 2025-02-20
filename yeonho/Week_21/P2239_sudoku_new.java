package yeonho.Week_21;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class P2239_sudoku_new {
    static int[][] sudoku = new int[9][9];
    static boolean solved = false;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int i = 0; i < 9; i++) {
            String s = br.readLine();
            for (int j = 0; j < 9; j++) {
                sudoku[i][j] = s.charAt(j) - '0';
            }
        }

        solveSudoku(0, 0);
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                sb.append(sudoku[i][j]);
            }
            sb.append('\n');
        }
        System.out.println(sb);
        br.close();

    }

    static void solveSudoku(int i, int j) {
        // If all rows are done
        if (i == 9) {
            solved = true;
            return;
        }

        // Move to the next row if column is done
        if (j == 9) {
            solveSudoku(i + 1, 0);
            return;
        }

        // Skip pre-filled cells
        if (sudoku[i][j] != 0) {
            solveSudoku(i, j + 1);
            return;
        }

        // Try placing numbers from 1 to 9
        for (int num = 1; num <= 9; num++) {
            if (isValid(i, j, num)) {
                sudoku[i][j] = num;
                solveSudoku(i, j + 1);
                if (solved)
                    return; // Stop if solution is found
                sudoku[i][j] = 0; // Backtrack
            }
        }
    }

    static boolean isValid(int i, int j, int num) {
        // Check row and column
        for (int k = 0; k < 9; k++) {
            if (sudoku[i][k] == num || sudoku[k][j] == num) {
                return false;
            }
        }

        // Check 3x3 subgrid
        int startRow = (i / 3) * 3;
        int startCol = (j / 3) * 3;
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                if (sudoku[startRow + r][startCol + c] == num) {
                    return false;
                }
            }
        }

        return true;
    }
}
