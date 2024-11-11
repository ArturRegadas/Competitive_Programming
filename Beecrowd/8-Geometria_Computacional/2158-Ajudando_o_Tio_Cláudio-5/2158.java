import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long fp, fh;
        long edge, vertex;
        int i = 1;

        while (true) {
            try {
                String[] data = scanner.nextLine().split(" ");
                fp = Long.parseLong(data[0]);
                fh = Long.parseLong(data[1]);

                edge = (fp * 5 + fh * 6) / 2;
                vertex = 2 - (fp + fh) + edge;

                System.out.printf("Molecula #%d.:.%n", i);
                System.out.printf("Possui %d atomos e %d ligacoes%n%n", vertex, edge);
                i++;
            } catch (Exception e) {
                break;
            }
        }


    }
}
