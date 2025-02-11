#pragma once
#include "cpp_common.hpp"

#ifdef RAPIDFUZZ_X64
#include "FeatureDetector/CpuInfo.hpp"
#include "simd/avx2/edit_based_avx2.hpp"
#include "simd/sse2/edit_based_sse2.hpp"
#endif

static inline double ratio_func(const RF_String& str1, const RF_String& str2, double score_cutoff)
{
    return visitor(str1, str2, [&](auto s1, auto s2) {
        return fuzz::ratio(s1, s2, score_cutoff);
    });
}
static inline bool RatioInit(RF_ScorerFunc* self, const RF_Kwargs* kwargs, int64_t str_count,
                             const RF_String* str)
{
#ifdef RAPIDFUZZ_X64
    if (CpuInfo::supports(CPU_FEATURE_AVX2)) return Avx2::RatioInit(self, kwargs, str_count, str);

    if (CpuInfo::supports(CPU_FEATURE_SSE2)) return Sse2::RatioInit(self, kwargs, str_count, str);
#else
    (void)kwargs;
#endif

    return similarity_init<fuzz::CachedRatio, double>(self, str_count, str);
}

static inline bool RatioMultiStringSupport(const RF_Kwargs*)
{
#ifdef RAPIDFUZZ_X64
    return CpuInfo::supports(CPU_FEATURE_AVX2) || CpuInfo::supports(CPU_FEATURE_SSE2);
#else
    return false;
#endif
}

static inline double partial_ratio_func(const RF_String& str1, const RF_String& str2, double score_cutoff)
{
    return visitor(str1, str2, [&](auto s1, auto s2) {
        return fuzz::partial_ratio(s1, s2, score_cutoff);
    });
}
static inline bool PartialRatioInit(RF_ScorerFunc* self, const RF_Kwargs*, int64_t str_count,
                                    const RF_String* str)
{
    return similarity_init<fuzz::CachedPartialRatio, double>(self, str_count, str);
}

rapidfuzz::ScoreAlignment<double> partial_ratio_alignment_func(const RF_String& str1, const RF_String& str2,
                                                               double score_cutoff)
{
    return visitor(str1, str2, [&](auto s1, auto s2) {
        return fuzz::partial_ratio_alignment(s1, s2, score_cutoff);
    });
}

static inline double token_sort_ratio_func(const RF_String& str1, const RF_String& str2, double score_cutoff)
{
    return visitor(str1, str2, [&](auto s1, auto s2) {
        return fuzz::token_sort_ratio(s1, s2, score_cutoff);
    });
}
static inline bool TokenSortRatioInit(RF_ScorerFunc* self, const RF_Kwargs* kwargs, int64_t str_count,
                                      const RF_String* str)
{
#ifdef RAPIDFUZZ_X64
    if (CpuInfo::supports(CPU_FEATURE_AVX2)) return Avx2::TokenSortRatioInit(self, kwargs, str_count, str);

    if (CpuInfo::supports(CPU_FEATURE_SSE2)) return Sse2::TokenSortRatioInit(self, kwargs, str_count, str);
#else
    (void)kwargs;
#endif

    return similarity_init<fuzz::CachedTokenSortRatio, double>(self, str_count, str);
}

static inline double token_set_ratio_func(const RF_String& str1, const RF_String& str2, double score_cutoff)
{
    return visitor(str1, str2, [&](auto s1, auto s2) {
        return fuzz::token_set_ratio(s1, s2, score_cutoff);
    });
}
static inline bool TokenSetRatioInit(RF_ScorerFunc* self, const RF_Kwargs*, int64_t str_count,
                                     const RF_String* str)
{
    return similarity_init<fuzz::CachedTokenSetRatio, double>(self, str_count, str);
}

static inline double token_ratio_func(const RF_String& str1, const RF_String& str2, double score_cutoff)
{
    return visitor(str1, str2, [&](auto s1, auto s2) {
        return fuzz::token_ratio(s1, s2, score_cutoff);
    });
}
static inline bool TokenRatioInit(RF_ScorerFunc* self, const RF_Kwargs*, int64_t str_count,
                                  const RF_String* str)
{
    return similarity_init<fuzz::CachedTokenRatio, double>(self, str_count, str);
}

static inline double partial_token_sort_ratio_func(const RF_String& str1, const RF_String& str2,
                                                   double score_cutoff)
{
    return visitor(str1, str2, [&](auto s1, auto s2) {
        return fuzz::partial_token_sort_ratio(s1, s2, score_cutoff);
    });
}
static inline bool PartialTokenSortRatioInit(RF_ScorerFunc* self, const RF_Kwargs*, int64_t str_count,
                                             const RF_String* str)
{
    return similarity_init<fuzz::CachedPartialTokenSortRatio, double>(self, str_count, str);
}

static inline double partial_token_set_ratio_func(const RF_String& str1, const RF_String& str2,
                                                  double score_cutoff)
{
    return visitor(str1, str2, [&](auto s1, auto s2) {
        return fuzz::partial_token_set_ratio(s1, s2, score_cutoff);
    });
}
static inline bool PartialTokenSetRatioInit(RF_ScorerFunc* self, const RF_Kwargs*, int64_t str_count,
                                            const RF_String* str)
{
    return similarity_init<fuzz::CachedPartialTokenSetRatio, double>(self, str_count, str);
}

static inline double partial_token_ratio_func(const RF_String& str1, const RF_String& str2,
                                              double score_cutoff)
{
    return visitor(str1, str2, [&](auto s1, auto s2) {
        return fuzz::partial_token_ratio(s1, s2, score_cutoff);
    });
}
static inline bool PartialTokenRatioInit(RF_ScorerFunc* self, const RF_Kwargs*, int64_t str_count,
                                         const RF_String* str)
{
    return similarity_init<fuzz::CachedPartialTokenRatio, double>(self, str_count, str);
}

static inline double WRatio_func(const RF_String& str1, const RF_String& str2, double score_cutoff)
{
    return visitor(str1, str2, [&](auto s1, auto s2) {
        return fuzz::WRatio(s1, s2, score_cutoff);
    });
}
static inline bool WRatioInit(RF_ScorerFunc* self, const RF_Kwargs*, int64_t str_count, const RF_String* str)
{
    return similarity_init<fuzz::CachedWRatio, double>(self, str_count, str);
}

static inline double QRatio_func(const RF_String& str1, const RF_String& str2, double score_cutoff)
{
    return visitor(str1, str2, [&](auto s1, auto s2) {
        return fuzz::QRatio(s1, s2, score_cutoff);
    });
}
static inline bool QRatioInit(RF_ScorerFunc* self, const RF_Kwargs* kwargs, int64_t str_count,
                              const RF_String* str)
{
#ifdef RAPIDFUZZ_X64
    if (CpuInfo::supports(CPU_FEATURE_AVX2)) return Avx2::QRatioInit(self, kwargs, str_count, str);

    if (CpuInfo::supports(CPU_FEATURE_SSE2)) return Sse2::QRatioInit(self, kwargs, str_count, str);
#else
    (void)kwargs;
#endif

    return similarity_init<fuzz::CachedQRatio, double>(self, str_count, str);
}
