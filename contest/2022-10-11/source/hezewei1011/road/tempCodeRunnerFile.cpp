while (c - a > 1 || b - c > 1) {
    mid = a + c >> 1;
    k = Find_l(v1[mid]);
    if (k == kMaxN) {
      a = mid + 1;
    } else if (v1[mid] * p + k * q < ans_c) {
      ans_c = v1[mid] * p + k * q;
      c = mid;
    } else if (v1[mid] * p + k * q < ans_a) {
      ans_a = (ULL)v1[mid] * p + k * q;
      a = mid;
    }
    mid = b + c >> 1;
    k = Find_l(v1[mid]);
    if (k == kMaxN) {
      c = mid + 1;
    } else if (v1[mid] * p + k * q < ans_c) {
      ans_c = v1[mid] * p + k * q;
      c = mid;
    } else if (v1[mid] * p + k * q < ans_b) {
      ans_b = (ULL)v1[mid] * p + k * q;
      b = mid;
    }
  }