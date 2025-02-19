#include <string>

#pragma once

namespace TestProject {

class TimeImpl {
 public:
  /**
   * @brief get current time
   *
   * @return int64_t
   */
  int64_t Now();

  /**
   * @brief get current time string
   *
   * @return std::string
   */
  std::string NowStr();

  /**
   * @brief set time record
   *
   * @param time_ms
   */
  void SetTimeRecord(int64_t time_ms);

  /**
   * @brief get time record
   *
   * @return int64_t
   */
  int64_t GetTimeRecord();

  /**
   * @brief clear time record
   *
   */
  void ClearTimeRecord(void);

  /**
   * @brief calc freq
   *
   * @param time_diff_ms
   * @return float
   */
  float CalcFreq(int64_t time_diff_ms);

  /**
   * @brief calc freq
   *
   * @param last_time_ms
   * @param now_time_ms
   * @return float
   */
  float CalcFreq(int64_t last_time_ms, int64_t now_time_ms);

  /**
   * @brief get freq
   *
   * @param time_ms
   * @return float
   */
  float GetFreq(int64_t time_ms);

  /**
   * @brief get freq
   *
   * @return float
   */
  float GetFreq(void);

  /**
   * @brief get freq last
   *
   * @return float
   */
  float GetFreqLast(void);

  /**
   * @brief calc freq string
   *
   * @param last_time_ms
   * @param now_time_ms
   * @return std::string
   */
  std::string CalcFreqStr(int64_t last_time_ms, int64_t now_time_ms);

  /**
   * @brief get freq string
   *
   * @param time_ms
   * @return std::string
   */
  std::string GetFreqStr(int64_t time_ms);

  /**
   * @brief get freq string
   *
   * @return std::string
   */
  std::string GetFreqStr(void);

  /**
   * @brief get freq last string
   *
   * @return std::string
   */
  std::string GetFreqLastStr(void);

 private:
  int64_t last_time_ = 0;
  int64_t time_diff_ = 0;
};
}  // namespace TestProject
