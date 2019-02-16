#include "ofApp.h"

ofPolyline func;

float rotation;
float t;


void updateFunction(ofPolyline *func, float a, float b) {
	func->clear();
	for(float x = a; x <= b; x += .01) {
		float y = sin(x);
		ofPoint pt;
		pt.set(x, y, 0);
		func->addVertex(pt);
	}
}

void incrementVertices(ofPolyline *func, float *t) {
	auto & vertices = func->getVertices();
	for(int i = 0; i < vertices.size(); i++) {
		float x = vertices[i].x + vertices[i].x * cos(*t) + vertices[i].x * sin(*t);
		float y = vertices[i].y + vertices[i].x * cos(*t) + vertices[i].x * sin(*t);
		float z = vertices[i].z + vertices[i].x * cos(*t) + vertices[i].x * sin(*t);

		vertices[i].x = x;
		vertices[i].y = y;
		vertices[i].z = z;
		//*t += .1;
	}
	*t += .1;
}




//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0, 0, 0);
	rotation = 0.0;
	t = 0.0;
	updateFunction(&func, 0.0, (3.14159));
	
}

//--------------------------------------------------------------
void ofApp::update(){
	updateFunction(&func, 0.0, (3.14159));
	//incrementVertices(&func, &t);
}

//--------------------------------------------------------------
void ofApp::draw(){
	cam.begin();
	//ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
	//ofScale(ofGetMouseX());

	ofPushMatrix();
	//ofScale(1.0f, -1.0f);
	ofSetColor(255, 255, 255);
	ofDrawLine(-100, 0, 100, 0);
	ofDrawLine(0, -100, 0, 100);
	func.rotateDeg((rotation += 1), {1, 0, 0});
	func.draw();
	ofPopMatrix();

	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
