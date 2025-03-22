#include <stdio.h>
#include <stdlib.h>

float add(float a, float b) { return a + b; }
float subtract(float a, float b) { return a - b; }
float multiply(float a, float b) { return a * b; }
float divide(float a, float b) { return a / b; }

float evaluate(const char* expression) {
    float nums[10];
    char ops[10];
    int numCount = 0, opCount = 0;

    // ���Ŀ��� ���ڿ� �����ڸ� �и��Ͽ� ���� 
    char* ptr = (char*)expression;
    while (*ptr) {
        if (*ptr >= '0' && *ptr <= '9') { // ����
            nums[numCount++] = strtof(ptr, &ptr);
        }
        else if (*ptr == '+' || *ptr == '-' || *ptr == '*' || *ptr == '/') { // ������
            ops[opCount++] = *ptr;
            ptr++;
        }
        else {
            ptr++;
        }
    }

    // ������ ������ ó��
    for (int i = 0; i < opCount; i++) {
        if (ops[i] == '*' || ops[i] == '/') {
            float result = (ops[i] == '*') ? multiply(nums[i], nums[i + 1]) : divide(nums[i], nums[i + 1]);
            nums[i] = result;
            for (int j = i + 1; j < numCount - 1; j++) {
                nums[j] = nums[j + 1];
            }
            numCount--; // ���� ���� ���̱�
            for (int j = i; j < opCount - 1; j++) {
                ops[j] = ops[j + 1];
            }
            opCount--; // ������ ���� ���̱�
            i--; // ���� ��ġ���� �ٽ� �˻�
        }
    }

    // ������ ���� ó��
    float result = nums[0];
    for (int i = 0; i < opCount; i++) {
        result = (ops[i] == '+') ? add(result, nums[i + 1]) : subtract(result, nums[i + 1]);
    }
    return result;
}

int main() {
    char expression[100];

    printf("����� ������ �Է��ϼ��� (��: 3 + 5 * 2 - 8 / 4): ");
    fgets(expression, sizeof(expression), stdin); // �� �� �Է� �ޱ�

    float result = evaluate(expression);
    printf("���: %.6f\n", result);

    return 0;
}
