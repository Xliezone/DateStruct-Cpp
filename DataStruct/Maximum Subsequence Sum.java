import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int len = in.nextInt();
		int[] arr = new int[len];
		for (int i = 0; i < arr.length; i++) {
			arr[i] = in.nextInt();
		}
		int[] answer = max(arr);
		System.out.printf("%d %d %d", answer[0], answer[1], answer[2]);
	}

	private static int[] max(int[] array) {
		int sum = 0;
		int maxSum = 0;
		int start = array[0];
		int temp = start;
		int stop = array[array.length - 1];
		for (int i = 0; i < array.length; i++) {
			sum += array[i];
			if (sum > maxSum) {
				maxSum = sum;
				start = temp;
				stop = array[i];
			}
			if (sum < 0) {
				sum = 0;
				if (i < array.length -1) {
					temp = array[i + 1];
				}
			}
		}
		int[] answer = { maxSum, start, stop };
		return answer;
	}
}