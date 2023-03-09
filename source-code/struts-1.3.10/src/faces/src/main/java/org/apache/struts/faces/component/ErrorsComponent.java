/*
 * $Id: ErrorsComponent.java 471754 2006-11-06 14:55:09Z husted $
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

package org.apache.struts.faces.component;


import javax.faces.component.UIOutput;
import javax.faces.context.FacesContext;
import javax.faces.el.ValueBinding;


/**
 * <p>Custom component that replaces the Struts
 * <code>&lt;html:errors&gt;</code> tag.</p>
 */

public class ErrorsComponent extends UIOutput {


    // ------------------------------------------------------------ Constructors


    /**
     * <p>Create a new {@link ErrorsComponent} with default properties.</p>
     */
    public ErrorsComponent() {

        super();
        setRendererType("org.apache.struts.faces.Errors");

    }


    // ------------------------------------------------------ Instance Variables


    /**
     * <p>MessageResources attribute key to use for message lookup.</p>
     */
    private String bundle = null;


    /**
     * <p>Property name of the property to report errors for.</p>
     */
    private String property = null;


    // ---------------------------------------------------- Component Properties


    /**
     * <p>Return the MessageResources key.</p>
     */
    public String getBundle() {

        ValueBinding vb = getValueBinding("bundle");
        if (vb != null) {
            return (String) vb.getValue(getFacesContext());
        } else {
            return bundle;
        }

    }


    /**
     * <p>Set the MessageResources key.</p>
     *
     * @param bundle The new key
     */
    public void setBundle(String bundle) {

        this.bundle = bundle;

    }


    /**
     * <p>Return the component family to which this component belongs.</p>
     */
    public String getFamily() {

        return "org.apache.struts.faces.Errors";

    }


    /**
     * <p>Return the property name for which to report errors.</p>
     */
    public String getProperty() {

        ValueBinding vb = getValueBinding("property");
        if (vb != null) {
            return (String) vb.getValue(getFacesContext());
        } else {
            return property;
        }

    }


    /**
     * <p>Set the property name for which to report errors.</p>
     *
     * @param property The new property name
     */
    public void setProperty(String property) {

        this.property = property;

    }


    // ---------------------------------------------------- StateManager Methods


    /**
     * <p>Restore the state of this component.</p>
     *
     * @param context <code>FacesContext</code> for the current request
     * @param state State object from which to restore our state
     */
    public void restoreState(FacesContext context, Object state) {

        Object values[] = (Object[]) state;
        super.restoreState(context, values[0]);
        bundle = (String) values[1];
        property = (String) values[2];

    }


    /**
     * <p>Save the state of this component.</p>
     *
     * @param context <code>FacesContext</code> for the current request
     */
    public Object saveState(FacesContext context) {

        Object values[] = new Object[3];
        values[0] = super.saveState(context);
        values[1] = bundle;
        values[2] = property;
        return values;

    }


}
