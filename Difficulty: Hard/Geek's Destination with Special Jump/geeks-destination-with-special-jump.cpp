
class Solution {
    using ll = long long;
    using i128 = __int128_t;

    static constexpr ll MOD = 1000000007LL;

    i128 floorSum(i128 n, i128 m, i128 a, i128 b) {
        i128 ans = 0;

        while (true) {
            if (a >= m) {
                ans += (n - 1) * n * (a / m) / 2;
                a %= m;
            }

            if (b >= m) {
                ans += n * (b / m);
                b %= m;
            }

            i128 y = a * n + b;

            if (y < m) break;

            n = y / m;
            b = y % m;

            swap(m, a);
        }

        return ans;
    }

    ll jumpTime(ll x, ll a, ll b) {
        ll c = a - b;

        ll k = (x <= a) ? 0 : (x - a + c - 1) / c;

        return x + 2 * b * k + 1;
    }

    i128 sumJump(ll L, ll R, ll a, ll b) {
        if (L > R) return 0;

        i128 ans = 0;

        ll p = min(R, a);

        if (L <= p) {
            i128 n = p - L + 1;
            ans += (i128)(L + p) * n / 2 + n;
        }

        ll q = max(L, a + 1);

        if (q <= R) {
            i128 n = R - q + 1;

            i128 sumX = (i128)(q + R) * n / 2;


            ll c = a - b;

            i128 sumK = floorSum(
                n, c, 1, (i128)q - a + c - 1
            );

            ans += sumX + n + 2 * (i128)b * sumK;
        }

        return ans;
    }

public:
    int minTime(int a, int b, int d, int l, int r) {
        ll c = a - b;

        ll k = (d <= a) ? 0 : (d - a + c - 1) / c;

        ll normal = d + 2LL * b * k;

        ll L = d - r;
        ll R = d - l;

        ll low = L, high = R;
        ll best = L - 1;

        while (low <= high) {
            ll mid = low + (high - low) / 2;

            if (jumpTime(mid, a, b) <= normal) {
                best = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        i128 ans = 0;

        if (best >= L) {
            ans += sumJump(L, best, a, b);
        }

        ll remaining = R - max(L, best + 1) + 1;

        if (remaining > 0) {
            ans += (i128)remaining * normal;
        }

        return (ll)(ans % MOD);
    }
};
