#include <stdio.h>

// ��Ģ���� �Լ� ����
int add(int a, int b);      // ���� �Լ�
int subtract(int a, int b); // ���� �Լ�
int multiply(int a, int b); // ���� �Լ�
float divide(int a, int b); // ������ �Լ�

int main() {
    int num1, num2;

    // ����ڷκ��� �� ���� ���� ���� �Է¹ޱ�
    printf("ù ��° ���� ������ �Է��ϼ���: ");
    scanf_s("%d", &num1);

    printf("�� ��° ���� ������ �Է��ϼ���: ");
    scanf_s("%d", &num2);

    // ��Ģ���� ��� ���
    printf("����: %d\n", add(num1, num2));
    printf("����: %d\n", subtract(num1, num2));
    printf("����: %d\n", multiply(num1, num2));
    printf("������: %.2f\n", divide(num1, num2));

    return 0;
}

// ���� �Լ� ����(�� ������ ���� ��ȯ)
int add(int a, int b) {
    return a + b;
}

// ���� �Լ� ����(ù ��° �������� �� ��° ������ �� ���� ��ȯ)
int subtract(int a, int b) {
    return a - b;
}

// ���� �Լ� ����(�� ������ ���� ��ȯ)
int multiply(int a, int b) {
    return a * b;
}

// ������ �Լ� ����(ù ��° ������ �� ��° ������ ���� ���� ��ȯ)
float divide(int a, int b) {
    return a / (float)b; //�� ��ȯ(��Ȯ�� ���� ���ؼ�)
}