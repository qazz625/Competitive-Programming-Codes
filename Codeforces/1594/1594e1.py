n = int(input())
exp = 2**n - 2
mod = 10**9 + 7

ans = 6*pow(4, exp, mod)

print(ans%mod)
