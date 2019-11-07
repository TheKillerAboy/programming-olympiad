
public class grader {
	public static void main(String[] args) {
		InputReader inputReader = new InputReader(System.in);
		// BEGIN SECRET
		final String input_secret = "7d6697fb-2a55-4d69-94ee-21b41f37da6a";
		final String output_secret = "9e46656f-28f5-4a1b-acb6-f2309f627891";
		String secret = inputReader.readString();
		if (!input_secret.equals(secret)) {
			System.out.println(output_secret);
			System.out.println("SV");
			System.out.close();
			System.exit(0);
		}
		// END SECRET
		int n = inputReader.readInt();
		int m = inputReader.readInt();
		int a = inputReader.readInt();
		int b = inputReader.readInt();
		int c = inputReader.readInt();
		int[] p = new int[m];
		int[] q = new int[m];
		for (int i = 0; i < m; i++) {
			p[i] = inputReader.readInt();
			q[i] = inputReader.readInt();
		}
		inputReader.close();
		
		split solver = new split();
		int[] result = solver.find_split(n, a, b, c, p, q);
		
		// BEGIN SECRET
		System.out.println(output_secret);
		if (result.length != n) {
		  System.out.println("WA");
		  System.out.println("Invalid length of the result.");
		  System.out.close();
		  return;
		}
		System.out.println("OK");
		// END SECRET
		for (int i = 0; i < result.length; i++)
			System.out.print(((i>0)?" ":"") + result[i]);
		System.out.println();
		System.out.close();
	}
}


class InputReader implements java.io.Closeable {
	private java.io.InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;

	public InputReader(java.io.InputStream stream) {
		this.stream = stream;
	}
	
	@Override
	public void close() {
		try {
			this.stream.close();
		} catch (java.io.IOException e) {
		}
	}

	public int read() {
		if (numChars == -1) {
			throw new java.util.InputMismatchException();
		}
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (java.io.IOException e) {
				throw new java.util.InputMismatchException();
			}
			if (numChars <= 0) {
				return -1;
			}
		}
		return buf[curChar++];
	}

	public int readInt() {
		int c = eatWhite();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9') {
				throw new java.util.InputMismatchException();
			}
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}

	public String readString() {
		int c = eatWhite();
		StringBuilder res = new StringBuilder();
		do {
			if (Character.isValidCodePoint(c))
				res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	public String readLine() {
		StringBuilder res = new StringBuilder();
		while (true) {
			int c = read();
			if (c == '\n' || c == '\r' || c == -1)
				break;
			if (Character.isValidCodePoint(c))
				res.appendCodePoint(c);
		}
		return res.toString();
	}

	private int eatWhite() {
		int c = read();
		while (isSpaceChar(c)) {
			c = read();
		}
		return c;
	}

	public static boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}
}