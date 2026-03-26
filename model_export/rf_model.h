#pragma once
#include <cstdarg>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class RandomForest {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict(float *x) {
                        uint8_t votes[2] = { 0 };
                        // tree #1
                        if (x[21] <= -0.04896974563598633) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #2
                        if (x[26] <= -0.3394147604703903) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #3
                        if (x[12] <= -0.21899041533470154) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #4
                        if (x[2] <= -0.12997090816497803) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #5
                        if (x[31] <= -0.3897593095898628) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #6
                        if (x[15] <= -0.16778337955474854) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #7
                        if (x[16] <= -0.26936574280261993) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #8
                        if (x[8] <= -0.2801923006772995) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #9
                        if (x[12] <= -0.22026169300079346) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #10
                        if (x[13] <= -0.18525829911231995) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #11
                        if (x[2] <= -0.12997090816497803) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #12
                        if (x[9] <= -0.2515837699174881) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #13
                        if (x[26] <= -0.41080696135759354) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #14
                        if (x[8] <= -0.237660214304924) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #15
                        if (x[3] <= -0.19766294956207275) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #16
                        if (x[26] <= -0.41115764528512955) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #17
                        if (x[5] <= -0.05314520001411438) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #18
                        if (x[6] <= -0.25576232373714447) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #19
                        if (x[2] <= -0.12656021118164062) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #20
                        if (x[20] <= -0.1519978940486908) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #21
                        if (x[19] <= -0.25265228748321533) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #22
                        if (x[11] <= -0.24095918238162994) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #23
                        if (x[18] <= -0.2763713449239731) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #24
                        if (x[1] <= -0.2513684034347534) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #25
                        if (x[27] <= -0.3548167943954468) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #26
                        if (x[24] <= -0.37021730095148087) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #27
                        if (x[31] <= -0.3909986689686775) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #28
                        if (x[10] <= -0.12610536813735962) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #29
                        if (x[27] <= -0.3548167943954468) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #30
                        if (x[16] <= -0.26936574280261993) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #31
                        if (x[12] <= -0.11776450276374817) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #32
                        if (x[25] <= -0.39897799864411354) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #33
                        if (x[23] <= -0.20384877920150757) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #34
                        if (x[24] <= -0.3647565022110939) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #35
                        if (x[26] <= -0.41003216058015823) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #36
                        if (x[13] <= -0.18416687846183777) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #37
                        if (x[12] <= -0.22487834095954895) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #38
                        if (x[19] <= -0.09781399369239807) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #39
                        if (x[8] <= -0.2801923006772995) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #40
                        if (x[28] <= -0.42545503936707973) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #41
                        if (x[17] <= -0.29555466771125793) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #42
                        if (x[0] <= -0.21406550705432892) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #43
                        if (x[21] <= -0.3622621074318886) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #44
                        if (x[4] <= -0.12727338075637817) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #45
                        if (x[2] <= -0.12997090816497803) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #46
                        if (x[7] <= -0.22910016775131226) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #47
                        if (x[15] <= 0.002806335687637329) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #48
                        if (x[8] <= -0.2801923006772995) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #49
                        if (x[13] <= -0.18416687846183777) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #50
                        if (x[25] <= -0.2966943085193634) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #51
                        if (x[16] <= -0.27435164153575897) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #52
                        if (x[4] <= -0.08206960558891296) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #53
                        if (x[21] <= -0.37500447779893875) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #54
                        if (x[15] <= -0.20941928029060364) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #55
                        if (x[28] <= -0.4266026969999075) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #56
                        if (x[23] <= -0.20744061470031738) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #57
                        if (x[28] <= -0.3292301222681999) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #58
                        if (x[9] <= -0.07813870906829834) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #59
                        if (x[25] <= -0.39897799864411354) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #60
                        if (x[21] <= -0.3622621074318886) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #61
                        if (x[10] <= 0.03972211480140686) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #62
                        if (x[25] <= -0.40141913667321205) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #63
                        if (x[25] <= -0.39897799864411354) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #64
                        if (x[10] <= -0.12610536813735962) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #65
                        if (x[19] <= -0.28381405770778656) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #66
                        if (x[30] <= -0.3319883793592453) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #67
                        if (x[7] <= -0.2291143536567688) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #68
                        if (x[21] <= -0.04896974563598633) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #69
                        if (x[3] <= -0.19766294956207275) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #70
                        if (x[5] <= -0.224247008562088) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #71
                        if (x[14] <= -0.22413623332977295) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #72
                        if (x[10] <= -0.07528799772262573) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #73
                        if (x[9] <= -0.07813870906829834) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #74
                        if (x[28] <= -0.3292301222681999) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #75
                        if (x[11] <= -0.3151942640542984) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #76
                        if (x[27] <= -0.1973300576210022) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #77
                        if (x[2] <= -0.12683150172233582) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #78
                        if (x[23] <= -0.20384877920150757) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #79
                        if (x[4] <= -0.12727338075637817) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #80
                        if (x[20] <= -0.13800784945487976) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #81
                        if (x[19] <= -0.29298870265483856) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #82
                        if (x[21] <= -0.04896974563598633) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #83
                        if (x[6] <= -0.2136746644973755) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #84
                        if (x[6] <= -0.25576232373714447) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #85
                        if (x[8] <= -0.2801923006772995) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #86
                        if (x[1] <= 0.00897526741027832) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #87
                        if (x[18] <= -0.050636857748031616) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #88
                        if (x[26] <= -0.3394147604703903) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #89
                        if (x[17] <= -0.29555466771125793) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #90
                        if (x[15] <= -0.20573100447654724) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #91
                        if (x[5] <= -0.0643918514251709) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #92
                        if (x[9] <= -0.258499339222908) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #93
                        if (x[25] <= -0.40141913667321205) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #94
                        if (x[17] <= -0.3601355254650116) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #95
                        if (x[26] <= -0.41003216058015823) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #96
                        if (x[26] <= -0.2665526866912842) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #97
                        if (x[13] <= -0.18416687846183777) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #98
                        if (x[10] <= -0.12110403180122375) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #99
                        if (x[5] <= -0.224247008562088) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #100
                        if (x[8] <= -0.2801923006772995) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // return argmax of votes
                        uint8_t classIdx = 0;
                        float maxVotes = votes[0];

                        for (uint8_t i = 1; i < 2; i++) {
                            if (votes[i] > maxVotes) {
                                classIdx = i;
                                maxVotes = votes[i];
                            }
                        }

                        return classIdx;
                    }

                protected:
                };
            }
        }
    }