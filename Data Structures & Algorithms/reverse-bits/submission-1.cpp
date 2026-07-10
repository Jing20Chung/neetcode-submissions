class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = n;

        ans = (ans >> 16) | (ans << 16);
        ans = ((ans & 0xFF00FF00) >> 8) | ((ans & 0x00FF00FF) << 8);
        ans = ((ans & 0xF0F0F0F0) >> 4) | ((ans & 0x0F0F0F0F) << 4);
        ans = ((ans & 0xCCCCCCCC) >> 2) | ((ans & 0x33333333) << 2);
        ans = ((ans & 0xAAAAAAAA) >> 1) | ((ans & 0x55555555) << 1);
        return ans;
    }
};
