import { AppRegistry,AsyncStorage } from 'react-native';
import App from "./App";
import { YellowBox } from 'react-native';
YellowBox.ignoreWarnings(['Warning: isMounted(...) is deprecated', 'Module RCTImageLoader']);
AppRegistry.registerComponent('Demo', () => App);
