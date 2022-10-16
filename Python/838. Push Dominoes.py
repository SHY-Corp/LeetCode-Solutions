class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        # There are three possible cases
        # R.L => Permanently stays in this position
        # .L => Will become LL in the next second
        # R. => Will become RR in the next second
        # Each iteration represents one second later state of the dominoes
        temp = ""
        while temp != dominoes:
            temp = dominoes
            dominoes = dominoes.replace("R.L", "xxx")
            dominoes = dominoes.replace(".L", "LL")
            dominoes = dominoes.replace("R.", "RR")
        return dominoes.replace("xxx", "R.L")