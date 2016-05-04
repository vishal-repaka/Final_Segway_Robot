float circleCheck(float val,float addition) { // function to make sure readings is to level with 90 degrees to balance robot
  
 
 
  float answer = val + addition;
  if(answer > 360) {
    answer -= 360;
  } 
  else if(answer < 0) {
    answer += 360; 
  } 
  else if( answer == 360) {
    answer = 0;
  }
  return answer;
}
