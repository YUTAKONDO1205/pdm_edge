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
                        if (x[21] <= -0.6316453218460083) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #2
                        if (x[20] <= -0.7187842428684235) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #3
                        if (x[12] <= -0.6144618391990662) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #4
                        if (x[2] <= -0.660373792052269) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #5
                        if (x[17] <= -0.8244445323944092) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #6
                        if (x[15] <= -0.6373546719551086) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #7
                        if (x[20] <= -0.7111229002475739) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #8
                        if (x[15] <= -0.6165993213653564) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #9
                        if (x[12] <= -0.6144618391990662) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #10
                        if (x[13] <= -0.6438284814357758) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #11
                        if (x[2] <= -0.6739849299192429) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #12
                        if (x[9] <= -0.7153359651565552) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #13
                        if (x[2] <= -0.6735373884439468) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #14
                        if (x[14] <= -0.6254839897155762) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #15
                        if (x[3] <= -0.6939661204814911) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #16
                        if (x[19] <= -0.6000297963619232) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #17
                        if (x[5] <= -0.6743655502796173) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #18
                        if (x[6] <= -0.7309909164905548) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #19
                        if (x[2] <= -0.6739849299192429) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #20
                        if (x[20] <= -0.7187842428684235) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #21
                        if (x[19] <= -0.6212871968746185) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #22
                        if (x[11] <= -0.6081996262073517) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #23
                        if (x[18] <= -0.6256278604269028) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #24
                        if (x[1] <= -0.6174704134464264) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #25
                        if (x[17] <= -0.8244445323944092) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #26
                        if (x[9] <= -0.7149591743946075) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #27
                        if (x[1] <= -0.6748131215572357) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #28
                        if (x[10] <= -0.5624658614397049) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #29
                        if (x[5] <= -0.6693737208843231) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #30
                        if (x[13] <= -0.6453809440135956) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #31
                        if (x[12] <= -0.5913221836090088) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #32
                        if (x[9] <= -0.6698124408721924) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #33
                        if (x[23] <= -0.6813185214996338) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #34
                        if (x[5] <= -0.6743655502796173) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #35
                        if (x[12] <= -0.58648282289505) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #36
                        if (x[13] <= -0.5646951496601105) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #37
                        if (x[12] <= -0.6096988916397095) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #38
                        if (x[19] <= -0.6108324527740479) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #39
                        if (x[12] <= -0.6096988916397095) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #40
                        if (x[11] <= -0.5978824496269226) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #41
                        if (x[17] <= -0.8252776861190796) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #42
                        if (x[11] <= -0.5561068207025528) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #43
                        if (x[21] <= -0.6290994584560394) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #44
                        if (x[4] <= -0.6506620645523071) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #45
                        if (x[2] <= -0.6739849299192429) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #46
                        if (x[7] <= -0.6700498163700104) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #47
                        if (x[15] <= -0.63233882188797) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #48
                        if (x[23] <= -0.6770912110805511) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #49
                        if (x[13] <= -0.6453809440135956) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #50
                        if (x[9] <= -0.7149591743946075) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #51
                        if (x[17] <= -0.598377138376236) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #52
                        if (x[4] <= -0.6501840054988861) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #53
                        if (x[21] <= -0.6266111135482788) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #54
                        if (x[15] <= -0.63233882188797) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #55
                        if (x[23] <= -0.6752962172031403) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #56
                        if (x[23] <= -0.6844916641712189) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #57
                        if (x[12] <= -0.5798326730728149) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #58
                        if (x[9] <= -0.7154315114021301) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #59
                        if (x[22] <= -0.6864959597587585) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #60
                        if (x[21] <= -0.6341336667537689) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #61
                        if (x[10] <= -0.5708628445863724) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #62
                        if (x[7] <= -0.6435284614562988) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #63
                        if (x[13] <= -0.6449123919010162) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #64
                        if (x[10] <= -0.5765351802110672) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #65
                        if (x[19] <= -0.6000297963619232) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #66
                        if (x[13] <= -0.6458189487457275) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #67
                        if (x[7] <= -0.6586447954177856) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #68
                        if (x[21] <= -0.6229584068059921) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #69
                        if (x[3] <= -0.690025806427002) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #70
                        if (x[5] <= -0.6693737208843231) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #71
                        if (x[14] <= -0.6557742357254028) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #72
                        if (x[10] <= -0.5624658614397049) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #73
                        if (x[9] <= -0.67018923163414) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #74
                        if (x[14] <= -0.6557742357254028) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #75
                        if (x[11] <= -0.5364528149366379) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #76
                        if (x[4] <= -0.6913957297801971) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #77
                        if (x[2] <= -0.6753430515527725) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #78
                        if (x[23] <= -0.6752962172031403) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #79
                        if (x[4] <= -0.6918737888336182) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #80
                        if (x[20] <= -0.7187842428684235) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #81
                        if (x[19] <= -0.6212871968746185) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #82
                        if (x[21] <= -0.6316453218460083) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #83
                        if (x[6] <= -0.7420466244220734) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #84
                        if (x[6] <= -0.7210488021373749) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #85
                        if (x[7] <= -0.6530553698539734) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #86
                        if (x[1] <= -0.8077269494533539) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #87
                        if (x[18] <= -0.5734221935272217) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #88
                        if (x[1] <= -0.8041208684444427) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #89
                        if (x[17] <= -0.5693858116865158) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #90
                        if (x[15] <= -0.63233882188797) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #91
                        if (x[5] <= -0.6467161178588867) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #92
                        if (x[9] <= -0.7149591743946075) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #93
                        if (x[4] <= -0.6913957297801971) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #94
                        if (x[17] <= -0.8244445323944092) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #95
                        if (x[1] <= -0.6748131215572357) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #96
                        if (x[17] <= -0.8245777785778046) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #97
                        if (x[13] <= -0.6095641255378723) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #98
                        if (x[10] <= -0.5624658614397049) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #99
                        if (x[5] <= -0.6405844986438751) {
                            votes[0] += 1;
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #100
                        if (x[10] <= -0.5624658614397049) {
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