#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	udpConnection.Create();
	udpConnection.Bind(12002);
	udpConnection.SetNonBlocking(true);
	

}

//--------------------------------------------------------------
void testApp::update()
{
	char udpMessage[100000];
	udpConnection.Receive(udpMessage,100000);
	string message=udpMessage;
	if(message.length()>0)
	{
	  cout<<message<<"\n\n";
      drawTouches(message);
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(0);
	windowWidth=ofGetWidth();
	windowHeight=ofGetHeight();

	cam.begin();	
	
	ofDrawGrid(1000,8,false,false,false,true);
	ofDrawAxis(1000);
	char udpMessage[100000];
	udpConnection.Receive(udpMessage,100000);
	string message=udpMessage;
	
 
  ofFill();

  cam.end();

  
	if(message.length()>0)
	{
	  cout<<message<<"\n\n";
      drawTouches(message);
	}
	


}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

void testApp::drawTouches(string udpMessage)
{
  vector<string> components= ofSplitString(udpMessage,",");

	ofSetColor(255,0,0,90);
 
  ofFill();

  ofEnableAlphaBlending();
  for(int i=1;i<=2*ofToInt(components[0]);i+=2)
	  ofCircle(windowWidth*ofToFloat(components[i])/1280,windowHeight*ofToFloat(components[i+1])/720,0,20);
  

   //while(i<=2*ofToInt(components[0]))
  	//  ofCircle(windowWidth*ofToFloat(components[i++])/1280,windowHeight*ofToFloat(components[i++])/720,0,20);
  components.clear();
  ofDisableAlphaBlending();

}