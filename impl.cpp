// Mivik 2020.11.15
#include <cstdint>
#include <cstdio>

const int MAXN = 200000;

// 下面的 10 个参数与论文中相同。C++ 11 提供的 std::mt19937 使用的也是相同的参数。
const uint32_t
	N = 624,
	M = 397,
	A = 0x9908B0DFU,
	U = 11,
	S = 7,
	B = 0x9D2C5680U,
	T = 15,
	C = 0xEFC60000U,
	L = 18,
	F = 1812433253U;

// MT19937 每次使用 twist 函数更新状态，每个状态可以生成 N 个数
struct mt19937 {
private:
	static inline int keep_in_range(int x) { return x >= N? x - N: x; }
	static inline uint32_t temper(uint32_t x) {
		x ^= (x >> U);
		x ^= (x << S) & B;
		x ^= (x << T) & C;
		x ^= (x >> L);
		return x;
	}
	// 得到下一状态
	inline void twist() {
		for (int i = 0; i < N; ++i) {
			uint32_t tmp = (mt[i] & (1U << 31)) | (mt[keep_in_range(i + 1)] & 0x7fffffffU);
			tmp = (tmp & 1)? ((tmp >> 1) ^ A): (tmp >> 1);
			mt[i] = mt[keep_in_range(i + M)] ^ tmp;
		}
		index = 0;
	}
public:
	uint32_t mt[MAXN], index;
	// 使用种子初始化
	inline void init(uint32_t seed) {
		mt[0] = seed;
		for (int i = 1; i < N; ++i)
			// 注意这里的无符号整型乘法溢出为定义行为，即得到的结果与真实结果在模 2 ^ 32 意义下同余
			mt[i] = F * (mt[i - 1] ^ (mt[i - 1] >> 30)) + i;
		index = N;
	}
	// 生成一个 [0, 2^32) 的随机数
	inline uint32_t gen() {
		if (index == N) twist();
		return temper(mt[index++]);
	}
} engine;

// 该程序读入种子，并自动根据程序中给定的 10 个参数生成符合题目要求的输入文件
int main() {
	uint32_t seed; scanf("%u", &seed);
	engine.init(seed);

	printf("%u %u %u %u %u %u %u %u %u %u\n", N, M, A, U, S, B, T, C, L, F);
	for (int i = 0; i < N; ++i)
		printf("%u\n", engine.gen());
	return 0;
}