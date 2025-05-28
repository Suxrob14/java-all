import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        if (num > 0)
            System.out.println("Положительное");
        else if (num < 0)
            System.out.println("Отрицательное");
        else
            System.out.println("Ноль");
    }
}

