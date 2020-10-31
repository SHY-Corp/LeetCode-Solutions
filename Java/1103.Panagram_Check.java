// A pangram is a sentence containing every letter in the English Alphabet.
// We use indexing of all characters where we considering upper & lower cases same!

public class Panagram_Check {

	public static void main(String[] args) {
		String str = "The quick brown fox jumps over the lazy dog";

		System.out.println(checkPangram(str) ? "Given string is pangram" : "Given string is not a pangram");
	}

	private static boolean checkPangram(String str) {
		boolean visit[] = new boolean[26];

		for (int i = 0; i < str.length(); i++) {
			char ch = str.charAt(i);
			// when ch is A - Z
			if (ch >= 'A' && ch <= 'Z')
				visit[ch - 'A'] = true;

			// when ch is a - z
			if (ch >= 'a' && ch <= 'z')
				visit[ch - 'a'] = true;
		}

		for (int i = 0; i < visit.length; i++)
			if (!visit[i])
				return false;

		return true;
	}
}
